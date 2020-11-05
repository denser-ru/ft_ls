set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab

syntax on 
set nocompatible
set number

set colorcolumn=80
highlight ColorColumn ctermbg=darkgray
set mouse=a

augroup project
    autocmd!
    autocmd BufRead,BufNewFile *.h,*.c set filetype=c.doxygen
augroup END

let &path.="src,inc,/usr/include/AL,"

"autocmd vimenter * NERDTree
map <C-n> :NERDTreeToggle<CR>

