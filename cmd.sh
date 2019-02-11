#!/bin/bash
#set -x #echo on

BASEDIR=`pwd`
unamestr=`uname`
BUILD_DIR=
VCPKG=

prepBuild() {
    set -x #echo on
    rm -rf $BASEDIR/$BUILD_DIR;
    mkdir $BASEDIR/$BUILD_DIR;
    cd $BASEDIR/$BUILD_DIR;
    cmake .. -DCMAKE_TOOLCHAIN_FILE=$VCPKG/scripts/buildsystems/vcpkg.cmake
}

case $1 in
    run-target)
        cmake --build $BASEDIR/$2 --target $4 -- -j 4; $BASEDIR/$2/$3/$4
        ;;
    prep-build)
        BUILD_DIR=$2 VCPKG=$3 prepBuild
        ;;
    sub.update)
        rm -rf $BASEDIR/worker-rpc/svc $BASEDIR/worker-fn/svc
        git config -f .gitmodules --get-regexp '^submodule\..*\.path$' |
        while read path_key path
        do
            url_key=$(echo $path_key | sed 's/\.path/.url/')
            url=$(git config -f .gitmodules --get "$url_key")
            git submodule add --force $url $path
            cd $path && git reset master@{upstream} && git pull && cd ..
        done
        ;;
    dyna.tbl.create)
        aws dynamodb create-table --table-name $2 --attribute-definitions AttributeName=id,AttributeType=S --key-schema AttributeName=id,KeyType=HASH --provisioned-throughput ReadCapacityUnits=5,WriteCapacityUnits=5 --endpoint-url $3
        ;;
    dyna.tbl.list)
        aws dynamodb list-tables --endpoint-url $2 --output json
        ;;
    aws-delete-alarms)
        aws cloudwatch delete-alarms --alarm-names $2
        ;;
    build_wasm_fn)
        rustup override set nightly
        cargo +nightly build --target wasm32-unknown-unknown --release
        mkdir -p worker-fn/wasm
        wasm-bindgen target/wasm32-unknown-unknown/debug/hello_world_wasm.wasm --nodejs --out-dir worker-fn/wasm
        ;;
    esac
exit 0
