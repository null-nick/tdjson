#!/usr/bin/env bash

# Install Xcode command line tools
xcode-select --install || echo "Xcode command line tools already installed"

# Install Homebrew if not installed
if ! command -v brew &>/dev/null; then
    echo "Installing Homebrew..."
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
else
    echo "Homebrew already installed"
fi

# Install dependencies
brew install gperf cmake openssl

# Clone and build TDLib
git clone --depth 1 https://github.com/tdlib/td.git
cd td
rm -rf build
mkdir build
cd build

cmake -DCMAKE_BUILD_TYPE=Release \
      -DOPENSSL_ROOT_DIR=$(brew --prefix openssl) \
      -DCMAKE_INSTALL_PREFIX:PATH=../tdlib \
      -DTD_ENABLE_LTO=ON ..

cmake -DCMAKE_BUILD_TYPE=Release \
      -DOPENSSL_ROOT_DIR=/opt/homebrew/opt/openssl/ \
      -DCMAKE_INSTALL_PREFIX:PATH=/usr/local \
      -DTD_ENABLE_LTO=ON ..

cmake --build . --target install -j$(sysctl -n hw.ncpu)

# Show built files
ls -l ../tdlib