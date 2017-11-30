# Hand-Build Deep Neural Network

## Goal
The goal of this project is to build a system that allows the user to design a neural network to apply to a standard dataset. After training, the user can compare results with different neural network configurations.

## Data
The dataset is a series of numbers, comma seperated, corresponding to the columns defined below.
`clump_thickness,unif_cell_size,unif_cell_shape,marg_adhesion,single_epith_cell_size,bare_nuclei,bland_chrom,norm_nucleoli,mitosis,class`

In this dataset, the `class` value is either 2 or 4. If the patient was diagnosed with breast cancer, a 4 is assigned. Otherwise a 2 is assigned. The goal of this neural network is to correctly predict the patient's class based on the other data related to a tested tumor

## Design
This neural network is atypical, in that it is built to work with a number of design patterns. More specifically, when building the neural network, an **Abstract Visitor** pattern is used. The network also features an abnormally high usage of Object Oriented programming. This allows each component of the neural network to be it's own object. When interconnected and functioning, this implements the **Composite Pattern**.

![](uml.jpg)
