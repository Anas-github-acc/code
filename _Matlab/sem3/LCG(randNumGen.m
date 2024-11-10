% linear congruential generator
n = 10000;

seed = 100;

a = 7^5;              % Multiplier
c = 0;                % Increment
m = 2^31 - 1;         % Modulus

linear_congruential_generator(n, seed, a, c, m);

function linear_congruential_generator(n, seed, a, c, m)

    % Initialize the array upto n for random numbers
    X = zeros(1, n);
    r = zeros(1, n);
    % range [1,10]
    p = 10;
    q = 1;

    X(1) = seed;
    r(1) = p + (q - p)*(X(1)/m);

    % Generate random numbers using the LCG formula and adding to array
    for i = 2:n
        X(i) = mod((a * X(i-1) + c), m);
        r(i) = p + (q - p)*(X(i)/m);
    end

    % Plot the random number distribution
    figure;
    subplot(2, 1, 1);
    histogram(r, "Normalization", "PDF");
    xlabel("Random Number");
    ylabel("Frequency");
    title("Random Number Distribution");

    % Normalize the generated numbers for CDF plot
    X_normalized = X / sum(X);

    % Plot CDF
    subplot(2, 1, 2);
    cdfplot(X_normalized);
    title("Cumulative Distribution Function");
    xlabel("Random Number (Normalized)");
    ylabel("CDF");
end