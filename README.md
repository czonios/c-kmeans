# Artificial Neural Networks
> A library of classic fully connected artificial neural networks in C.

<!-- [Project Website](https://czonios.github.io/c-kmeans) -->

This implementation of artificial neural networks contains functions for creating, training and predicting with custom neural networks.

The user can specify the number of layers, as well as the number of neurons each layer has, the activation functions, the input and output dimensions and more.

<!-- ![](header.png) -->

## Installation

### Linux

Clone the repository:

```sh
git clone https://github.com/czonios/c-kmeans.git
```

Change your directory and compile:

```sh
cd c-kmeans/src
make
```

Clean the intermediate objects and debugging derivative files:

```sh
make clean
```

## Usage example

The ``mlp_settings.h`` file contains the settings of the neural network.

```sh
# uses the default settings from mlp_settings.h
# x_file contains the inputs as a 2D array (num_samples X num_inputs)
# t_file contains the targets as a 2D array (num_samples X num_inputs)
./main x_file t_file
```

_For more examples and usage, please refer to the [Wiki][wiki]._

## Debugging

You can readily use GDB debugger by running:

```sh
make debug
gdb debug
```

## Release History

* 0.1-alpha
    * Work in progress

## Meta

Christos A. Zonios – [@czonios](https://twitter.com/czonios) – czonios (at) gmail (dot) com

Distributed under the MIT license. See ``LICENSE`` for more information.

[https://github.com/czonios/c-kmeans](https://github.com/czonios/c-kmeans)

## Contributing

1. Fork it (<https://github.com/czonios/c-kmeans/fork>)
2. Create your feature branch (`git checkout -b feature/fooBar`)
3. Commit your changes (`git commit -am 'Add some fooBar'`)
4. Push to the branch (`git push origin feature/fooBar`)
5. Create a new Pull Request

<!-- Markdown link & img dfn's -->
<!-- [travis-image]: https://img.shields.io/travis/dbader/node-datadog-metrics/master.svg?style=flat-square
[travis-url]: https://travis-ci.org/dbader/node-datadog-metrics -->
[wiki]: https://github.com/czonios/c-kmeans/wiki
