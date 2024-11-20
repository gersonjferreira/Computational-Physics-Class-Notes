# Installing and configuring a Debian Cluster

Below, all commands starting with the prompt `$` are meant to be run as a normal user, while commands starting with `#` must be run as **superuser (root)**. Each computer of the cluster will be called **a node**.

## Installing Debian

First, download and install Debian. The ISO is available at [https://cdimage.debian.org/debian-cd/current-live/amd64/iso-hybrid/]. I recommend the Gnome version for beginners. 

To partition the disc:

1. Reduce the Windows partition to 150 GB
2. Using the new free space, create an extended partition
3. Add the following Linux partitions and mount points
    - /boot, type ext4 with 1000 MiB
    - linuxswap, with 4000 MiB
    - /, type ext4 with 50000 MiB
    - /home, type ext4 with the remaining free space

In all computers, set the same username and password for the admin. For the hostnames, follow the numerical pattern suggested in class (labfc##). 

## Upgrading the packages

To become superuser, run `$ sudo su -`. [[sudo tutorial](https://linuxacademy.com/blog/linux/linux-commands-for-beginners-sudo/)].

Now let's edit the apt configuration to add the contrib and non-free sections to the list of packages. Let's use the **nano** editor, run `# nano /etc/apt/sources.list` and add `contrib non-free` to all lines after `main`. [[apt sources documentation](https://wiki.debian.org/SourcesList)]

To update the package list, and upgrade the system, run:

`# apt update`

`# apt dist-upgrade`

## Install openSSH and set hosts

Install the openSSH server on all machines running `# apt install openssh-server`. For more about SSH, check [some tricks](https://linuxacademy.com/blog/linux/ssh-and-scp-howto-tips-tricks/), a [tutorial](https://www.cyberciti.biz/faq/ubuntu-linux-install-openssh-server/).

After the installation, enable the server running `# systemctl start sshd`. For more about systemctl, [click here](https://www.digitalocean.com/community/tutorials/how-to-use-systemctl-to-manage-systemd-services-and-units)

The configuration file for the SSH server is at */etc/ssh/sshd_config*, check also `$ man ssh`

Now, let's configure the **/etc/hosts** with the IP and hostnames of all machines. Use **nano** to edit the hosts files and add the IP and hostnames at the end, for example:

> 192.168.1.10    labfc1<br>
192.168.1.13    labfc2

## Passwordless SSH for root

Our goal is to set passwordless SSH **for root**, but first let's check how it would be done for a normal user, which is much simpler. 

#### Digression: for a normal user

Let's say you want to access the machine *labfc2* from *labfc1* over SSH without password:

1. on *labfc1*, create a ssh key running `$ ssh-keygen`, use the default options to all questions. [More info here](https://www.ssh.com/ssh/keygen)
2. copy this key to *labfc2* running `$ ssh-copy-id labfc2`, you'll be prompted for the user password (here I'm assuming all users are the same). [More info here](https://www.ssh.com/ssh/copy-id)
3. now try to access `$ ssh labfc2`, it should work with password.

Now, to do this for the root superuser, the *ssh-copy-id* command won't work because root access over SSH is blocked by default in */etc/ssh/sshd_config*. To solve this, we need to find a way to broadcast the ssh key to all computers. We will either have to edit **/etc/ssh/sshd_config** to temporarily allow for root access, or copy the keys using USB pendrives. Check [this link](https://www.rittmanmead.com/blog/2014/12/linux-cluster-sysadmin-ssh-keys/).

### Back to the root

Now... **'don't take the name of root in vain'**, it's an old say. See also [XKCD/149](https://xkcd.com/149/).

The steps described here are slightly different from what we did in class, but they are equivalent. For a similar tutorial, [click here](https://www.rittmanmead.com/blog/2014/12/linux-cluster-sysadmin-ssh-keys/).

From time to time, we'll need to install packages and edit config files on all machines. To do that, it's better to be able to run scripts on one machine and propagate it to all. But they need to be run as *root*. To prepare the cluster to allow for this type of broadcast, **do the following in all computers**:

1. Make sure openssh-server is installed in all computers (see above).
2. Edit */etc/ssh/sshd_config* and change the option *PermitRootLogin* to **yes**. This will be temporarily.
3. Run `# systemctl restart sshd` to restart the SSH server with the new option activated.
4. Set up a root password using `# passwd`. This will be temporarily.

Now we can create a SSH key and copy it to all machines. On the first node, **labfc1**, let's create the SSH key and set up the **authorized_keys** file:

5. Create a key and save it to */root/.ssh/keyroot* running `# ssh-keygen -f /root/.ssh/keyroot -q -N`. 

The command above creates a private key *keyroot* and a public one *keyroot.pub* in the folder */root/.ssh*.

6. Copy the public key to the *authorized_keys* files, running `# cp /root/.ssh/keyroot.pub /root/.ssh/authorized_keys`.

Now, let's use `scp` (secure file copy) to broadcast these 3 files (*keyroot, keyroot.pub, authorized_keys*) to all computers:

7. Run `# scp -r /root/.ssh/* root@labfc2:/root/.ssh`, and the same for *labfc3, 4, 5, ...* 
 
The command above will prompt you for the root password. But this is the last time you'll have to type it. It's all done, we can test it from any node to any node:

8. To access another machine as root, run `# ssh -i /root/.ssh/keyroot labfc2`. You should access it without being prompt for a password.

### Bash script to broadcast a command to all machines

To test our setup, let's try this simple bash script run the password lock for root in all machines. On the first node (*labfc1*) prepare the file */root/broadcast.sh* as

```bash
#!/bin/bash

nodes='labfc1 labfc2 labfc3 labfc4 labfc5 labfc6 labfc7 labfc8 labfc9 labfc10 labfc11 labfc12 labfc13 labfc14'

for node in $nodes; do
    echo "Running on node $node"
    ssh -i /root/.ssh/keyroot $node passwd -l root
    echo "Finished node $node"
done
```

Give the file permission to execute, `# chmod +x /root/broadcast.sh`, and run it `# ./broadcast.sh`. Now the **root** user is locked away from password loggin, but it remains accessible via ssh using the keys we have generated.

Later we shall use scripts similar to the one above to broadcast other commands to all machines. For instance, to install deb packages.

### Challenge!!

Can you write a bash script that automatically edits the */etc/ssh/sshd_config* file on each machine back to the default option **#PermitRootLogin prohibit-password** and runs `# systemctl restart sshd` on each machine? **Tip: use `sed`**

### Other info

Some useful links I've found while preparing these notes:

- [Run a shell script in parallel](https://unix.stackexchange.com/questions/103920/parallelize-a-bash-for-loop)
- [Run Multiple SSH Command On Remote Machine](https://www.cyberciti.biz/faq/linux-unix-osx-bsd-ssh-run-command-on-remote-machine-server/)

