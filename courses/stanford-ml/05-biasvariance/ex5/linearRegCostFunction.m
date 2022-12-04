function [J, grad] = linearRegCostFunction(X, y, theta, lambda)
%LINEARREGCOSTFUNCTION Compute cost and gradient for regularized linear
%regression with multiple variables
%   [J, grad] = LINEARREGCOSTFUNCTION(X, y, theta, lambda) computes the
%   cost of using theta as the parameter for linear regression to fit the
%   data points in X and y. Returns the cost in J and the gradient in grad

% Initialize some useful values
m = length(y); % number of training examples

% You need to return the following variables correctly
J = 0;
grad = zeros(size(theta));

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost and gradient of regularized linear
%               regression for a particular choice of theta.
%
%               You should set J to the cost and grad to the gradient.
%

predictions = X * theta;
square_errors = (predictions - y)' * (predictions - y);
theta_regJ = theta(2:end);
J = square_errors / (2 * m) + ((lambda ./ (2 * m)) .* (theta_regJ' * theta_regJ));

residuals = ((X * theta) - y);
grad = (X' * residuals) ./ m;

theta_reggrad = theta;
theta_reggrad(1) = 0;
theta_reggrad = (lambda / m) .* theta_reggrad;
grad = grad + theta_reggrad;










% =========================================================================

grad = grad(:);

end
