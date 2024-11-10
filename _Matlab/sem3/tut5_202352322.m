% Name - Mohd Anas
% Roll no - 202352322

function coin_toss_simulation(tossCount, biased_p)
% Step 0: Set the number of tosses
% tossCount = 10000;

% Step 1: Generate random numbers between 0 and 1 for each toss
rng(64); % for Reproducibility (seeding)
%rng('shuffle'); % time based seeding
fairCoinToss = rand(1, tossCount);

% Step 2: Simulate fair coin toss results (1 for heads, 0 for tails)
fairCoinResult = fairCoinToss >= 0.5;

% Step 3: Calculate cumulative sum of heads over tosses
fairCoinHeads = cumsum(fairCoinResult);

% Step 4: Generate the sequence of toss numbers
fairCoinTossNums = 1:tossCount;

% Step 5: Calculate the cumulative proportion of heads at each toss
fairCoinHeadProp = fairCoinHeads ./ fairCoinTossNums;

% Step 6: Plot results for fair coin
figure;
plot(fairCoinTossNums, fairCoinHeadProp);
title('Fair Coin Toss Simulation');
xlabel('Number of Tosses');
ylabel('Proportion of Heads');

% Repeat the process for a biased coin with probability of heads as some 'p'
% biased_p = 0.7; % probability of heads
biasedCoinToss = rand(1, tossCount);
biasedCoinResults = biasedCoinToss < biased_p;
biasedCoinHeads = cumsum(biasedCoinResults);
biasedCoinTossNums = 1:tossCount;
biasedCoinHeadProp = biasedCoinHeads ./ biasedCoinTossNums;

figure;
plot(biasedCoinTossNums, biasedCoinHeadProp);
title(['Biased Coin Toss Simulation (p = ', num2str(biased_p), ')']);
xlabel('Number of Tosses');
ylabel('Proportion of Heads');

% My observations
% 1. Fair coin: Proportion of heads converges to 0.5, demonstrating the Weak Law of Large Numbers.
% 2. Fair coin simulation exhibits slower convergence compared to the biased coin, due to more random fluctuations.
% 3. Biased coin: Proportion of heads converges to the biased probability, following the Strong Law.
% 4. Biased coin simulation converges faster than the fair coin, as the biased probability creates a more pronounced trend.
end

coin_toss_simulation(10000, 0.7);