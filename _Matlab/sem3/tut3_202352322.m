% Name : Mohd Anas
% college ID = 202352322

function coin_flip_simulation()
    p = 0.5;
    delta_p = 0.1;
    n = 100;  % Number of flips per trial
    N = 100000;  % Number of trials
    
    U = lcg(3*N*n, 100, 7^5, 0, 2^31);
    
    % Perform simulation
    [k1_values, k2_values, final_heads_counts, total_trials] = simulate_trials(N, n, p, delta_p, U);
    
    % Calculate empirical probabilities
    empirical_probabilities = calculate_empirical_probabilities(final_heads_counts, total_trials);
    
    % Plot results
    plot_results(k1_values, k2_values, empirical_probabilities, n);
end

% LCG function - generate random function
function U = lcg(N, seed, a, c, m)
    U = zeros(1, N);
    X = seed;
    for i = 1:N
        X = mod(a * X + c, m);
        U(i) = X / m;
    end
end

% Simulation function
function [k1_values, k2_values, final_heads_counts, total_trials] = simulate_trials(N, n, p, delta_p, U)
    k1_values = zeros(1, N);
    k2_values = zeros(1, N);
    final_heads_counts = zeros(1, 2*n + 1);
    total_trials = zeros(1, 2*n + 1);
    
    idx = 1;
    for i = 1:N
        % 1
        k1_values(i) = sum(U(idx:idx+n-1) < p);
        idx = idx + n;
        
        % 2
        p2 = p + (k1_values(i) > n/2) * delta_p;
        k2_values(i) = sum(U(idx:idx+n-1) < p2);
        idx = idx + n;
        
        % 3
        combined_heads = k1_values(i) + k2_values(i);
        final_flip = U(idx) < combined_heads / (2 * n);
        idx = idx + 1;
        
        % Update counts
        if final_flip
            final_heads_counts(combined_heads + 1) = final_heads_counts(combined_heads + 1) + 1;
        end
        total_trials(combined_heads + 1) = total_trials(combined_heads + 1) + 1;
    end
end

% Calculate empirical probabilities
function empirical_probabilities = calculate_empirical_probabilities(final_heads_counts, total_trials)
    empirical_probabilities = zeros(1, length(total_trials));
    for i = 1:length(total_trials)
        if total_trials(i) > 0
            empirical_probabilities(i) = final_heads_counts(i) / total_trials(i);
        end
    end
end

% Plot results
function plot_results(k1_values, k2_values, empirical_probabilities, n)
    % heads in both trials
    figure;
    histogram(k1_values, 'Normalization', 'probability', 'FaceColor', [1 0 0]);
    hold on;
    histogram(k2_values, 'Normalization', 'probability', 'FaceColor', [0 0 1]);
    title('Number of Heads in Both Trials');
    legend('1st Trial', '2nd Trial');
    hold off;
    
    % Conditional probability
    figure;
    theoretical_probabilities = (0:2*n) / (2*n);
    plot(0:2*n, empirical_probabilities, 'bo-', 'DisplayName', 'Empirical');
    hold on;
    plot(0:2*n, theoretical_probabilities, 'r--', 'DisplayName', 'Theoretical');
    title('Empirical vs. Theoretical Conditional Probabilities');
    legend('Empirical', 'Theoretical');
    hold off;
    
    % Cdf plotting
    figure;
    cdfplot(k1_values + k2_values);
    title('CDF of Total Heads Occured');
end

coin_flip_simulation();