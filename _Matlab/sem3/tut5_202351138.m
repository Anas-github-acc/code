% Name - Sourabh
% Roll no - 202351138

tossCount = 10000;
% Step 0: Set the number of tosses
% tossCount = 10000;

% Step 1: Generate random numbers between 0 and 1 for each toss
rng(42); % for reproducibility
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
biased_p = 0.6;
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

% 1. For the fair coin, as you repeat the experiment many times (ie increase n), we can expect that the percentage of heads out of all flips will become close to 50%, which is why it should be familiar from Weak Law if Large Numbers.

% 2. For the described biased coin, we should have seen that probability of heads approaching this biased_p value in our simulation.

% 3. The convergence of the fair coin simulation is slower than its biased counterpart.

% 4. The Strong Law of Large Numbers Unraveled This seemingly subtle exchange between limit and probability operations in the Strong Law of Large Numbers is brought out more clearly by simulating it for fair, FLLN or biased coins.