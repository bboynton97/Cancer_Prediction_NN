# Design Pattern Deep Neural Network

## Goal
The goal of this project is to build a system that allows the user to design a neural network to apply to a standard dataset. The neural network will be built using as many applicable design patterns as possible.

## Data

Two datasets are available with the neural network for varied complexity.

### XOR
The first is an Exclusive OR (XOR) dataset. The user should construct the neural network with 2 nodes in the first layer and 1 in the last. When inferencing, each node can either be 1 or 0, ideally producing a value close to the intended XOR result.

### Breast Cancer

This is a popular neural network testing dataset. The dataset is a series of numbers, comma separated, corresponding to the columns defined below.
`clump_thickness,unif_cell_size,unif_cell_shape,marg_adhesion,single_epith_cell_size,bare_nuclei,bland_chrom,norm_nucleoli,mitosis,class`

In this dataset, the `class` value is either 0 or 1. If the patient was diagnosed with breast cancer, a 1 is assigned. Otherwise a 0 is assigned. The goal of this neural network is to correctly predict the patient's class based on the other data related to a tested tumor.

The user should construct the neural network with 9 input nodes and 1 output node. Each input value can be between 1 and 10.

## Design
This neural network is atypical, in that it is built to work with a number of design patterns. More specifically, when building the neural network, an **Abstract Builder** pattern is used. The network also features an abnormally high usage of Object Oriented programming. This allows each component of the neural network to be it's own object. When interconnected and functioning, this implements the **Composite Pattern**.

![](uml.jpg)

# Essay

This project was done for an IUPUI Design Patterns class, and the following is the corresponding essay.

## Background

Coming into this project, I have had a lot of experience building, fine-tuning and implementing neural networks in my occupation. All of my previous experience, however, involved the use of a preexisting framework or library such as TensorFlow or Theano. I was very familiar with the theory and mathematics behind the frameworks, but had never built a neural network from scratch. I was excited for the challenge.

As an additional challenge, before this class, I had never been exposed to design patterns. Without any out-of-class experience, I was to build a neural network using as many design patterns as possible.

## Goals

**Primary Goal**:
Build a functioning neural network using object oriented programming with as many applicable design patterns as possible.

**Secondary Goal**: Use a breast cancer diagnosis dataset to train the neural net to diagnose breast cancer at a reasonable accuracy. (Practical application of this project)

## Planning

Because this project relies so heavily on design patterns, it required a lot of white boarding and pre-planning. I spent quite a bit of time taking every component of a neural network, breaking it up into classes, thinking of the necessary functions, and designing the structure of just the neural network.

At that point, I started to look for places where design patterns could be used.

**Composite Pattern**

This was the most obvious. Because the neural network was being broken up into classes, it made the most sense to connect it in a composite. Each *net* has *layers*. Every layer is composed of *nodes* and every node owns a set of *connections* that correspond to every node in the last layer.

Altogether, you end up with a setup like this:

![](https://www.pyimagesearch.com/wp-content/uploads/2016/08/simple_neural_network_header.jpg)

**Builder Pattern**

From there, what's the best way to build a composite? Through a *builder* obviously. I set up the builder to work in a very straightforward way. The client creates a builder object, then generates the shape of the neural network by calling `.addLayer(int hm_nodes)`. That function then calls the builder's other functions, such as `.addNodes()`. This eventually creates a full neural network.

In my client, I ask the user to provide the topography of the neural network by inputting a string such as `9,4,1`. This would use the builder pattern to create a neural network with 3 layers. One input layer with 9 nodes, a hidden layer with 4 nodes, and a single node on the output layer.

**Iterator Pattern**

Throughout the execution of training and inferencing, there are a number of places where looping is essential. Rather than trying to get a variable to loop to, the iterator pattern has proven to work better. The iterator has a constructor function that takes in the layer or node that it is iterating through. It then collects the proper information and iterates through the appropriate variable for that object. This pattern is primarily used in the feed forward process. The preprocessor classes also server to work as an iterator in a sense. They iterate through the file, line by line, until the final line is reached.

## Running the program

When running the program, you will be prompted to choose your dataset (defined above). Because each dataset is different and requires different preprocessing, there is a Base_Preprocessor and then a separate Preprocessor for each dataset.

Once you choose the dataset to use, you'll be asked to design the shape of the neural network. This is done as explained before. As the program tells you, the number of input nodes should be equal to the number of inputs that the dataset provides. The number of output nodes should always be 1 because the program only constructs binary classifiers.

From there, you choose how many epochs to train for. An epoch is an entire run through the dataset. Too many epochs can lead to overfitting (which is bad and produces inaccurate results). Too little epochs can lead to underfitting (which is bad and produces inaccurate results).

After you hit enter, the model will train. Some insights into last accuracy and the average accuracy will be displayed every 100 rows trained.

Finally, the NN will stop training. At this point, the user can inference. This is when you give the neural network new data and see what the output is.

When finished inferencing, type `QUIT`.

## Known problems

Fortunately, by and large the program works well. The known errors consists mostly of NN training bugs. This is largely due to the activation function and loss function used in the backpropegation process.

For the activation function, a `tanh` function is used. This is a fairly old and outdated activation function. It was chosen because it is the most straightforward activation function and can easily be implemented with all the design patterns being used. Ideally, a larger-scale neural network would use a `RELU` or `leaky RELU` activation function on the hidden layers and a `softmax` function on the final layer. However, this was far outside the scope of the project.

The same principle applies to the loss function, but less so. This NN uses a `Root Mean Squared` loss function. This is sufficient for the datasets used, but wouldn't be ideal for more complicated datasets.

There are existing memory leaks that Valgrind identifies as "possibly lost", "still reachable", and "suppressed". The Valgrind documentation defines these as not true memory leaks and not to worry about them. I'm still worried about them. I have deleted everything I have created on the stack and have not gotten rid of the leaks at the time of this writing.

Finally, there are some exploding/vanishing gradient issues on both datasets. The XOR dataset provides the best accuracies, but because of the randomly initialized beginning connection weights, the gradients can still sometimes "explode" or "vanish". This can be seen when every inference does not return a value (exploding) or when every inference returns either 1 or 0 (vanishing). In this case, simply quit the program and restart to get better results.


## Challenges

Throughout the development process, there were certainly a number of problems that stumped me. Fortunately, with enough thinking, problem solving and the occasional Stack Overflow, the primary goal has been satisfied.

**Building a neural network with OO design**:

This challenge was inherently a part of the project. Neural networks aren't necessarily a good candidate for OO programming. Yes, they do have components that can be encapsulated in classes, however many experts believe unorganized matrix calculations can produce better accuracies in less time. With some whiteboarding and planning, it wasn't difficult to decide what components of the neural network to turn into classes and how to connect them.

**Writing the mathematics**:

Fortunately, [my occupation](http://vemity.com/) has given me a lot of experience with neural networks and other ML algorithms. I was already very familiar with the theory, and with the help of some diagrams and reference code, I could piece the mathematics together pretty easily.

**Getting it to run on Tesla (IUPUI CS SSH server)**:

It doesn't. *Why?*
Tesla has g++ 4.6.2 installed. The current version is 7.2.x. If you look at [a concrete preprocessor class](https://github.com/bboynton97/Design_Pattern_Neural_Network/blob/master/XOR_Preprocessor.cpp), it assigns the file to be read in the constructor. This assignment operator for `std::ifstream` is only supported in g++ 5.0+. Because the `ifstream` object is inherited, it cannot be given the filename in an initialization. Because of this, there is no way to support multiple preprocessors (and thus multiple datasets) while still providing support for g++ <5.0.

## Results

The final neural network has proven to perform relatively effectively. It is by no means groundbreaking, but for a neural network written from scratch, focusing on design patterns over accuracy, it performs well. Not only did I learn a decent bit on how to program a neural network, but I also gained knowledge on how to implement design patterns in a real-world, practical application.

## Additional Notes

**Why the Flyweight pattern was not used**:

Although it was suggested, it seems that the flyweight pattern would not be ideal for this project. It seems that the flyweight pattern is best for cases when you there are a number of objects that are all largely the same. While there are a lot of layers, nodes and connections, each object has specific values that make it unique. Because of this the flyweight pattern doesn't seem to be a good fit.

**Why the Visitor pattern was not used**:

The iterator is used to traverse the network. The network and it's nodes contain the logic for both feed forward and back propagation. To implement the visitor pattern properly, the visitor should be maintaining a state that performs the calculations. Because of the complexity and number of calculations, it is not appropriate to use a visitor for this task.

**Could this program handle other datasets?**:

In short, yes. The preprocessors classes could be expanded greatly. In practical applications, preprocessing can be just as complicated as the actual neural networks. These dataset are well groomed, perfect candidates for neural network training. Other binary classification datasets formatted in csv file style would also work.

**How do accuracies compare to accepted accuracies for these datasets?**:

With the XOR dataset, it is easy to get >99% accuracy with a 2,2,1 network. This is arguably the easiest dataset possible for a neural network and anything short of 95% is laughable.

The breast cancer dataset is slightly different. While there are easily identifiable patterns, it does make for an interesting 9-dimensional classification problem. Having use this dataset extensively at my job, it's easy to achieve greater than 90% accuracy regularly when using TensorFlow or other deep learning libraries. With this neural network, I've been steadily getting ~95% accuracies.

**Want to see some of the best worst code you have ever seen?**:

Check [this](https://github.com/bboynton97/Design_Pattern_Neural_Network/blob/master/brandon_print.h) out. (Extra credit for creativity?)
