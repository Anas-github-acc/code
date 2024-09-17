% Linear congruential generator
n = 10000;
s = 100;
a = 7^5; % Multiplier
c = 0;   % Increment
m = 2^31 - 1; % Modulus
X = zeros(1, n);

X(1) = s;

for i = 2:n
    X(i) = mod((a*X(i-1) +c),m); 
end

figure;
subplot(2,1,1);
histogram(X,"Normalization","PDF");
xlabel("RandNumber");
ylabel("Frequency");
title("Random Number Distribution");

% plot of CDF
X_normalized = X / sum(X);
subplot(2,1,2);
cdfplot(X_normalized)