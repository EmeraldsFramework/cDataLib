# cDataLib

A high performance library writter in C, containing multiple data structures.
Brings some cross platform features meant to be used mainly on embedded as well as highly efficient code bases.

[![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-yellow.svg)](./COPYING)

# Installation

`em list`
`em install`
`em build lib`

## Usage

* Include the headers and import the static libraries into the compilation

`touch test.c`

```c
#include "export/cDataLib.h"
```

`clang test.c $(find ./libs -name "*.*o" | xargs ls -d)`

## Development

* Make all parts of cDataLib an emerald library.

## Contributing

1. Fork it (<https://github.com/EmeraldsFramework/cDataLib/fork>)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request

## Contributors

- [Oblivious](https://github.com/Oblivious-Oblivious) - creator and maintainer
