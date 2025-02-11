# git-crypt to store answers

To store excercise answers on this repository, we use `git-crypt` to encrypt the files. This way, only the people with the correct key can access the files. This system encrypts the files before pushing them to the remote repository, and decrypts them on the local repository automatically.

## How to use it?

Before pushing any secret file, init git-crypt on your local repository:

```bash
# generates a key at .git/git-crypt/keys/default
$ git-crypt init
```

Then, specify the files you want to encrypt in the `.gitattributes` file:

```bash
# .gitattributes file
Respostas* filter=git-crypt diff=git-crypt
```

Now you can committ and push files safelly, they will be encrypted on the remote repository.

To check which files are encrypted on the remote, run:

```bash
$ git-crypt status -e
```

## Copy the key to another computer

Copy the key file to another computer. It is located at `.git/git-crypt/keys/default`. Do not run `git-crypt init`, instead clone the repository and run:

```bash
git-crypt unlock <path-to-key>
```
