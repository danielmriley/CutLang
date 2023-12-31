mkdir -p $PREFIX/bin

CUTLANG_DIR="$( dirname $( cd "$( dirname "$RECIPE_DIR" )" && pwd ) )"

cd $CUTLANG_DIR/CLA
make clean
cp -R $CUTLANG_DIR $PREFIX/bin/cutlang

rm -rf $PREFIX/bin/cutlang/.github
rm -rf $PREFIX/bin/cutlang/.git

cd $PREFIX/bin/cutlang/CLA
make

echo "build.sh done"

for CHANGE in "activate" "deactivate"
do
    mkdir -p "${PREFIX}/etc/conda/${CHANGE}.d"
    cp "${PREFIX}/bin/cutlang/scripts/conda/conda_${CHANGE}.sh" "${PREFIX}/etc/conda/${CHANGE}.d/${PKG_NAME}_${CHANGE}.sh"
    cp "${PREFIX}/bin/cutlang/scripts/conda/root_unset_for_conda.sh" "${PREFIX}/etc/conda/activate.d/__root_unset_for_conda.sh"
done