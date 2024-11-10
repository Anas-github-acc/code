%Name - Mohd Anas
%Roll no - 202352322

function face_pca_analysis()
    % Perform PCA on face images and reconstruct images with varying components.
    
    % Step 1: Load and prepare the dataset
    images_path = dir(fullfile("Image Dataset", '*jpg'));  % Load image paths
    n = 25;  % Number of images
    X = zeros(100*100, n);  % Matrix to store images as column vectors
    
    % Load images and convert to grayscale, resize to 100x100
    for i = 1:n
        image = imread("Image Dataset/" + images_path(i).name);
        image = rgb2gray(imresize(image, [100, 100]));
        X(:, i) = image(:);  % Flatten the image and store as a column vector
    end
    
    % Load self-image for visualization
    selfimage = imread("Image Dataset/self.jpg");
    selfimage = imresize(rgb2gray(selfimage), [100, 100]);

    % Step 2: Center the data by subtracting the mean
    m_x = mean(X, 2);  % Compute mean across rows (each pixel)
    X_centered = X - m_x;  % Mean-centered data

    % Step 3: Compute covariance matrix and eigen decomposition
    C_x = (1 / (n - 1)) * (X_centered' * X_centered);  % Covariance matrix
    [P, D] = eig(C_x);  % Eigen decomposition
    [D, index] = sort(diag(D), 'descend');  % Sort eigenvalues
    P = P(:, index);  % Sort eigenvectors by eigenvalue order

    % Step 4: Reconstruct the image using varying numbers of principal components
    error = zeros(1, n);  % Initialize error matrix to store reconstruction error

    for k = 1:n
        W = P(:, 1:k);  % Use top k principal components (eigenvectors)
        X_projected = X_centered * W;  % Project data onto the k-dimensional subspace
        X_reconstructed = X_projected * W' + m_x;  % Reconstruct data

        % Visualize the original and reconstructed image for specific k values
        if k == 1 || mod(k, 5) == 0
            figure;
            subplot(1, 2, 1);
            imshow(selfimage);
            title('Original Image');

            subplot(1, 2, 2);
            imshow(reshape(uint8(X_reconstructed(:, n)), [100, 100]));
            title(['Reconstructed with ', num2str(k), ' components']);
        end

        % Calculate and store reconstruction error using Frobenius norm
        error(k) = norm(X - X_reconstructed, 'fro');
    end

    % Step 5: Plot the reconstruction error for different numbers of components
    figure;
    plot(error, 'o-');
    xlabel('Number of Components');
    ylabel('Reconstruction Error');
    title('Error vs. Number of Principal Components');
    grid on;
end
