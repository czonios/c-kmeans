# K-Means in C
> An implementation of the k-means algorithm in C.

<!-- [Project Website](https://czonios.github.io/c-kmeans) -->

This implementation of the k-means algorithm contains functions for training and outputting the learned cluster centers. It also outputs the total dispersion of clustering, so you can run it multiple times with multiple different K and find the simplest solution that gives the least dispersion.

![Learned centers for the example dataset](https://github.com/czonios/c-kmeans/blob/master/graphs/kmeans.png)

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

The ``main.c`` file contains the defined settings of the algorithm.

```sh
./main
```

<!-- _For more examples and usage, please refer to the [Wiki][wiki]._ -->

## Generating a test dataset

The ``scripts`` directory includes a Python script that generates an example dataset. You can call it by using:

```sh
python create_clustering_dataset.py
```

## Debugging

You can readily use GDB debugger by running:

```sh
make debug
gdb debug
```

## Release History

* 0.1-alpha
    * Work in progress
* 1.0.0 2020-10-09
    * Initial full release

## Meta

Christos A. Zonios – [@czonios](https://czonios.github.io) – czonios (at) gmail (dot) com

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
