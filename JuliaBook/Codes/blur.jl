using Images
using PyPlot

img2 = separate(load("lena.png"));
red = img2.data[:,:,1];
green = img2.data[:,:,2];
blue = img2.data[:,:,3];

#0.2989 * R + 0.5870 * G + 0.1140 * B 
gray = 0.2989*red + 0.5870*green + 0.1140*blue;

#img = load("lenabw.png");
#data = transpose(convert(Array{Float64}, img.data));

data = gray;

sharpen = [0 -1 0; -1 5 -1; 0 -1 0]/1.0;
blur = ones(3,3)/9.0;
edge = [0 -1 0; -1 4 -1; 0 -1 0]/1.0;

function cutpixel(pixel)
    if pixel > 1.0
        return 1.0;
    elseif pixel < 0.0
        return 0.0;
    else
        return pixel;
    end
end

sharpened = conv2(sharpen, data);
x,y = size(sharpened);
sharpened = Float64[cutpixel(sharpened[i,j]) for i=1:x, j=1:y]

blured = conv2(blur, data);
x,y = size(blured);
blured = Float64[cutpixel(blured[i,j]) for i=1:x, j=1:y]

edges = conv2(edge, blured);
x,y = size(edges);
edges = Float64[cutpixel(edges[i,j]) for i=1:x, j=1:y]

clf();

subplot(221);
imshow(data; cmap="Greys");

subplot(222);
imshow(sharpened; cmap="Greys");

subplot(223);
imshow(blured; cmap="Greys");

subplot(224);
imshow(1-edges; cmap="Greys");


