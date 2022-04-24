for filename in `ls *[0-9]| grep -o .*[0-9]` ; do
    mv $filename* $filename
done
