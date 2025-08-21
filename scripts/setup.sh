source .venv/bin/activate
export PREFIX=$VIRTUAL_ENV
PYTHON_INCLUDE=$(python3 -c "import sysconfig; print(sysconfig.get_path('include'))")
PYTHON_LIB=$(python3 -c "import sysconfig; print(sysconfig.get_config_var('LIBDIR'))")
export LDFLAGS="-L/opt/homebrew/lib -L$PYTHON_LIB"
export CPPFLAGS="-I/opt/homebrew/include -I$PYTHON_INCLUDE"
export CXXFLAGS="-std=c++20"
export PYTHON_LDFLAGS="-L/opt/homebrew/lib -L$PYTHON_LIB"
export PYTHON_CXXFLAGS="-I/opt/homebrew/include -I$PYTHON_INCLUDE"
./configure --prefix=$PREFIX --enable-python --with-boost-python-suffix=313 > configure.out