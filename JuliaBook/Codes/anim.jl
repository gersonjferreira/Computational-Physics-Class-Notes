using PyCall
using PyPlot
@pyimport matplotlib.animation as anim

function animate(t)

    x = linspace(-10, 10, 200);
    c = 3*sin(2pi*t);
    y = exp(-(x-c).^2/2);

    clf();
    plot(x,y)
    
    return 0
end

fig = figure();
tspan = linspace(0, 5, 100);
video = anim.FuncAnimation(fig, animate, frames=tspan, interval=20)

video[:save]("anim.mp4", extra_args=["-vcodec", "libx264"])#, "-pix_fmt", "yuv420p"])

