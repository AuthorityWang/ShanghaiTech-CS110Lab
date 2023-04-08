# Scenario 1:

#### 1. What combination of parameters is producing the hit rate you observe? (Hint: Your answer should be the process of your calculation.)

Hit rate = 0, as 
#### 2. What is our hit rate if we increase Rep Count arbitrarily? Why?

Hit rate = 0, no matter how the rep count is. As 

#### 3.How could we modify our program parameters to maximize our hit rate?

By setting the step size to 1, we can maximize the hit rate.

# Scenario 2:

#### 1. What combination of parameters is producing the hit rate you observe? (Hint: Your answer should be the process of your calculation.)

Hit rate : 0.75

#### 2. What happens to our hit rate as Rep Count goes to infinity? Why?

The hit rate grows larger, and goes to 1, 

#### 3. Suppose we have a program that uses a very large array and during each Rep, we apply a different operator to the elements of our array (e.g. if Rep Count = 1024, we apply 1024 different operations to each of the array elements). How can we restructure our program to achieve a hit rate like that achieved in this scenario? (Assume that the number of operations we apply to each element is very large and that the result for each element can be computed independently of the other elements.) What is this technique called? (Hint)

The techinque is called Cache blocking or said to be loop tiling. The 

# Scenario 3:

#### 1. Run the simulation a few times. Every time, set a different seed value (bottom of the cache window). Note that the hit rate is non-deterministic. What is the range of its hit rate? Why is this the case? ("The cache eviction is random" is not a sufficient answer)

#### 2. Which Cache parameter can you modify in order to get a constant hit rate? Record the parameter and its value (and be prepared to show your TA a few runs of the simulation). How does this parameter allow us to get a constant hit rate? And explain why the constant hit rate value is that value.

#### 3. Ensure that you thoroughly understand each answer. Your TA may ask for additional explanations.

Hope I'm sure :(