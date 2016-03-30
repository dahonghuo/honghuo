#!/bin/sh
set -e

if [ $# = 0 ]; then	
  	echo -e "\033[40;33m"
		echo warming  your had not inputed assemble model
		echo "$PWD"
		echo autogen-honghuo-man [MODEL NAME]
		echo
		echo	EXAMPLE:
		echo
		echo	autogen-honghuo-man ["honghuo|honghuo-test|honghuo-ptest"]
	echo -e "\033[40;37m"
		exit 1
elif [ $# = 1 ]; then
	case $1 in 
		honghuo)
		flag1=--with-daemon
		;;
		honghuo-test)
		flag1=--enable-tests
		;;
		honghuo-ptest)
		flag1=--enable-ptests
		;;
		*)
		echo -e "\033[40;32m"
		echo warming:error para!
		echo -e "\033[40;37m"
		exit 1
		;;
	esac
elif [ $# = 2 ]; then
	case $1 in 
		honghuo)
		flag1=--with-daemon
		;;
		honghuo-test)
		flag1=--enable-tests
		;;
		honghuo-ptest)
		flag1=--enable-ptests
		;;
		*)
		echo -e "\033[40;32m"
		echo warming:error para!
		echo -e "\033[40;37m"
		exit 1
		;;
	esac
	case $2 in 
		honghuo)
		flag2=--with-daemon
		;;
		honghuo-test)
		flag2=--enable-tests
		;;
		honghuo-ptest)
		flag2=--enable-ptests
		;;
		*)
		echo -e "\033[40;32m"
		echo warming:error para!
		echo -e "\033[40;37m"
		exit 1
		;;
	esac
elif [ $# = 3 ]; then
	case $1 in 
		honghuo)
		flag1=--with-daemon
		;;
		honghuo-test)
		flag1=--enable-tests
		;;
		honghuo-ptest)
		flag1=--enable-ptests
		;;
		*)
		echo -e "\033[40;32m"
		echo warming:error para!
		echo -e "\033[40;37m"
		exit 1
		;;
	esac
	case $2 in 
		honghuo)
		flag2=--with-daemon
		;;
		honghuo-test)
		flag2=--enable-tests
		;;
		honghuo-ptest)
		flag2=--enable-ptests
		;;
		*)
		echo -e "\033[40;32m"
		echo warming:error para!
		echo -e "\033[40;37m"
		exit 1
		;;
	esac
	case $3 in 
		honghuo)
		flag3=--with-daemon
		;;
		honghuo-test)
		flag3=--enable-tests
		;;
		honghuo-ptest)
		flag3=--enable-ptests
		;;
		*)
		echo -e "\033[40;32m"
		echo warming:error para!
		echo -e "\033[40;37m"
		exit 1
		;;
	esac
else
	echo -e "\033[40;32m"
	echo warming  your had inputed illegal params
   	echo please insure the params in [honghuo|honghuo-test|honghuo-ptest]
	echo -e "\033[40;37m" 
	exit 1
fi

srcdir="$(dirname $0)"
cd "$srcdir"
autoreconf --install --force

CPPFLAGS="-std=c++11" \
./configure \
--disable-upnp-default \
--enable-debug \
--without-gui \
$flag1 \
$flag2 \
$flag3 \
$flag4 \
--with-protoc-bindir=/c/deps/protobuf-2.5.0/src \
--with-incompatible-bdb
