
%Step1 -- loading the face imsages
images_path = dir(fullfile("Image Dataset",'*jpg'));
%for i=1:length(images_path)
%    disp(i);
%    disp(images_path(i).name);
%end
n = 25; % number of images in the dataset
% display the number of images in the dataset

% Creating an emtpy matrix of 100*100 rows for each pixel of the image and 
% 25 columns for the number of images
% this will be our dataset matrix which we will construct our Covariance matrix
X = zeros(100*100,n);

% loading my self image
selfimage = imread("Image Dataset\self.jpg");

for i=1:n
    image = imread("Image Dataset/"+images_path(i).name);
    image = rgb2gray(image);
    image = imresize(image,[100,100]);
    if i==25
        selfimage = image;
    end
    X(:,i) = image(:);
end


%Mean centering the data 
m_x = mean(X);
X_centered = X-m_x;

% X store the column vectors of grayscaled version of every image
[m ,n] = size(X_centered);

%Step2 - Calculate the Covariance matrix using the formula for the image
%dataset X
C_x = (1/(n-1)).*(X_centered' * X_centered);

%Step3 - Find the eigenvalues and eigenvectors using decomposition
[P,D] = eig(C_x);

%Sort the eigenvalues and eigenvectors on basis of value of eigenvalue
D = diag(D);
[D,index] = sort(D,'descend');
P = P(:,index);

%initialising an error matrix to store the reconstruction error
error = zeros(1,25);

for k=1:n

    % Taking the top k eigenvectors
    W = P(:,1:k);

    %projecting the mean centered value onto the new basis i.e. the
    %eigenvectors with top eigenvalues as they are the top k principal
    %components of the data
    X_projected = X_centered * W; %16384*25 * 25*k

    %Recosntructing the matrix
    X_reconstructed = X_projected * W' + m_x;

    %Plotting the original and the reduced matrix for k = 1,5,10,15,20,25
    if k==10
        imwrite(reshape(uint8(X_reconstructed(:,n)),[100,100]),'myFace.jpeg');
    end
    if k==1 || mod(k,5) == 0
        figure
        subplot(1,2,1);
        
        imshow(selfimage);
        title("Original Image");
        reconstructed_image = reshape(uint8(X_reconstructed(:,n)),[100,100]);
        subplot(1,2,2);
        imshow(reconstructed_image);
        title("Image with " + k + " components");  
    end

    %Storing the error using the Frobenious norm
    error(1,k) = norm(X-X_reconstructed,'fro');
end

%Plotting the errors for every top k elements used to reconstruct the image
figure
plot(error,marker = 'o');
xlabel('Number of components used to recosntruct image')
ylabel('Error in reconstruction')
title('Reconstruction Error');
grid on


%Comments on Principal Component Analysis

%PCA