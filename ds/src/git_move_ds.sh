all()
{
    . git_move_ds.sh && move_files $1
    . git_move_ds.sh && symlink $1
    . git_move_ds.sh && makemake $1
    . git_move_ds.sh && add_com_push $1
}

backup()
{
    git add $1.c ../include/$1.h

    git commit -m "$1 uptodate"

    git push
}

move_files()
{
    mkdir $1

    git mv $1.c $1

    git mv ../include/$1.h $1
}

symlink()
{
    ln -s ../src/$1/$1.h ../include/$1.h
}

makemake()
{
    cp Makefile $1
}

add_com_push()
{
    git add $1/$1.c $1/$1.h

    git commit -m "moved $1 files"

    git push
}

