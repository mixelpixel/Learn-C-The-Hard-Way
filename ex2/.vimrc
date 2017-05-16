" per: http://superuser.com/questions/86246/where-should-the-vimrc-file-be-located-on-windows-7
" this will display line numbers

set number


" display the cursors line and column numbers
" NOTE: From the help of vim (command :help ruler):
" 'If the number of characters displayed is different from the number of bytes in the text
" (e.g., for a TAB or a multi-byte character), both the text column (byte number) and the
" screen column are shown, separated with a dash.'

set ruler


" turn programming syntax highlights ON:
" http://alvinalexander.com/linux/vi-vim-editor-syntax-highlighting

syntax on


" per http://stackoverflow.com/questions/1878974/redefine-tab-as-4-spaces
" changed from 4 to 2 spaces

set tabstop=2       " The width of a TAB is set to 4.
                    " Still it is a \t. It is just that
                    " Vim will interpret it to be having
                    " a width of 4.

set shiftwidth=2    " Indents will have a width of 4

set softtabstop=2   " Sets the number of columns for a TAB

" TURNED OFF TO USE WITH MAKEFILE
" set expandtab       " Expand TABs to spaces

" uncomment for 4 spaces
"
"set tabstop=4       " The width of a TAB is set to 4.
"                    " Still it is a \t. It is just that
"                    " Vim will interpret it to be having
"                    " a width of 4.
"
"set shiftwidth=4    " Indents will have a width of 4
"
"set softtabstop=4   " Sets the number of columns for a TAB
"
"set expandtab       " Expand TABs to spaces


