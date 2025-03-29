
Decision Tree can solve classification and regression problems.

Methodology : 
1. Select the best feature to split the data.
2. Split the data into two subsets.
3. Recursively apply the same methodology to each subset.
    while :
        - all leaves are pure (all samples belong to the same class)
        - all features are used
        - maximum depth is reached 

Common algorithms : 
- ID3
    - use entropy & information gain to select the best feature to split the data
    - advantage : simple to understand
    - disadvantage : prone to overfitting
- C4.5 (ID3 successor)
    - can handle numeric, categorical, and missing data
    - normalize gain ratio to avoid overfitting
    - automatically prune the tree (thanks to the information gain ratio)
- CART (superivised learning with geni for classification and MSE for regression)
    - use gini impurity to select the best feature to split the data
    - advantage : less prone to overfitting
    - disadvantage : more complex to understand
?? it's the lastest version ?

Definition : 
- MSE : mean squared error (Erreur quadratique moyenne)
- Entropy : measure of impurity
- Impurity : measure of how mixed the classes are in a node
- Pruning : remove the branches that are not useful
- Overfitting : when the tree is too complex and fits the training data too well, it will not generalize well to new data
- Outlier : a data point that is far from the others

!!!!!!!!! rework on it 
- Gain in information : measure of how much information is gained by splitting the data 
!!!!!!!!!!!!

- When to use a tree ? 
if :
- simple classification problem
- regression problem
- interpretability is important
- feature engineering with random forests or boosting
- non linear relationship between features and target
- small data set

and != :
- high dimensionality
- high noise
- high correlation between features
- complex relationships between features and target
- large data set



Choice between : 
- Tree
- Graph
- Matrix

- Weight ? Heuristic ? Cycles ? 



## Maths concepts 
- Gini(D)=1−∑i=1|y|p2(i)
- Entropy(D)=−∑i=1|y|p(i)log2p(i)
- Information gain = Entropy(parent) - [weighted average]Entropy(children)
- Gain(D, A) = Entropy(D) - ∑(|Dv|/|D|)Entropy(Dv)
- MSE = 1/n * ∑(y_i - y_pred_i)^2
- Gini impurity = 1 - ∑(p(i)^2)
- 


## Special cases :
- MAE : mean absolute error when high outliers
- Log Loss : boosting
- Huber Loss : regression quadratic & linear