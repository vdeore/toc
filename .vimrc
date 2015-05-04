set nocompatible    " use vim defaults
set ls=2            " allways show status line
set tabstop=4       " numbers of spaces of tab character
set shiftwidth=4    " numbers of spaces to (auto)indent
set showcmd         " display incomplete commands
set hlsearch        " highlight searches
set incsearch       " do incremental searching
set ruler           " show the cursor position all the time
set novisualbell    " turn off visual bell
set nobackup        " do not keep a backup file
set number          " show line numbers
set ignorecase      " ignore case when searching 
"set noignorecase   " don't ignore case
set title           " show title in console title bar
set ttyfast         " smoother changes
"set ttyscroll=0        " turn off scrolling, didn't work well with PuTTY
set modeline        " last lines in document sets vim mode
set modelines=3     " number lines checked for modelines
set shortmess=atI   " Abbreviate messages
set nostartofline   " don't jump to first character when paging
set whichwrap=b,s,h,l,<,>,[,]   " move freely between files
"set viminfo='20,<50,s10,h
set clipboard+=unnamed  

set autoindent     " always set autoindenting on
set smartindent        " smart indent
set cindent            " cindent
"set autowrite      " auto saves changes when quitting and swiching buffer
set expandtab      " tabs are converted to spaces, use only when required
"set sm             " show matching braces, somewhat annoying...
"set nowrap         " don't wrap lines
"set textwidth=80
set splitright 

set encoding=utf-8
set scrolloff=3
set showmode
set showcmd
set hidden
set wildmenu
set wildmode=list:longest
set visualbell
"set cursorline
set ttyfast
set ruler
set backspace=indent,eol,start
set laststatus=2
"set relativenumber
set undofile



"set mouse=a 

highlight OverLength ctermbg=darkred ctermfg=white guibg=#FFD9D9
match OverLength /\%80v.\+/


"match ErrorMsg /\%>80v.\+/
match ErrorMsg /[^\t]\zs\t\+/

syntax on           " syntax highlighing

if has("gui_running")
     " See ~/.gvimrc
     set guifont=Monospace\ 13  " use this font 
     set lines=50       " height = 50 lines
     set columns=100        " width = 100 columns
     "colorscheme desert    " use this color scheme
     colorscheme koehler    " use this color scheme
     set background=dark        " adapt colors for background
     set selectmode=mouse,key,cmd
     set keymodel=
else
     "colorscheme desert    " use this color scheme
     colorscheme koehler    "use this color scheme
     "colorscheme wombat256 "use this color scheme
     highlight Normal guibg=black guifg=white
     set background=dark        " adapt colors for background
     "set selectmode=mouse,key,cmd
endif

"set cursorline!
"set cursorcolumn!

filetype off
execute pathogen#infect()
filetype plugin indent on
set nocompatible
set modelines=0

nnoremap <leader>W :%s/\s\+$//<cr>:let @/=''<CR>

 au FileType helpfile nnoremap <buffer><bs> <c-T>   " Backspace to go back
if has("autocmd")
    " Restore cursor position
    au BufReadPost * if line("'\"") > 0|if line("'\"") <= line("$")|exe("norm '\"")|else|exe "norm $"|endif|endif
 
    " Filetypes (au = autocmd)
     au FileType helpfile set nonumber      " no line numbers when viewing help
     au FileType helpfile nnoremap <buffer><cr> <c-]>   " Enter selects subject
     au FileType helpfile nnoremap <buffer><bs> <c-T>   " Backspace to go back
 
     " When using mutt, text width=72
     au FileType mail,tex set textwidth=72
     "au FileType cpp,c,java,sh,pl,php,phtml,asp  set autoindent
     au FileType cpp,c,java,sh,pl,php,phtml,asp,xml,javascript  set smartindent
     nnoremap <C-p> :set invpaste paste?<CR>
     set pastetoggle=<C-p>
     set showmode
     "au FileType cpp,c,java,sh,pl,php,phtml,asp  set cindent
     "au BufRead mutt*[0-9] set tw=72
 
    " Automatically chmod +x Shell and Perl scripts
     "au BufWritePost   *.sh             !chmod +x %
     "au BufWritePost   *.pl             !chmod +x %
 
   " File formats
     au BufNewFile,BufRead  *.phtml  set syntax=php
     au BufNewFile,BufRead  *.pls    set syntax=dosini
     au BufNewFile,BufRead  modprobe.conf    set syntax=modconf
 
     " Ctrl+X O
     autocmd FileType python set omnifunc=pythoncomplete#Complete
     autocmd FileType javascript set omnifunc=javascriptcomplete#CompleteJS
     autocmd FileType html set omnifunc=htmlcomplete#CompleteTags
     autocmd FileType css set omnifunc=csscomplete#CompleteCSS
      autocmd FileType xml set omnifunc=xmlcomplete#CompleteTags
      autocmd FileType php set omnifunc=phpcomplete#CompletePHP
     autocmd FileType c set omnifunc=ccomplete#Complete
 
     autocmd FileType php noremap <C-L> :!php -l %<CR>
     autocmd Filetype html,xml,xsl source ~/.vim/closetag.vim

 endif
 
 " Keyboard mappings


map <C-L> :set number! number?<CR>
map <C-r> :cscope reset<CR>
map <F1> :previous<CR>  " map F1 to open previous buffer
"map <F2> :next<CR>      " map F2 to open next buffer
map <silent> <C-N> :silent noh<CR> " turn off highlighted search
map ,v :sp ~/.vimrc<cr> " edit my .vimrc file in a split
map ,e :e ~/.vimrc<cr>      " edit my .vimrc file
map ,u :source ~/.vimrc<cr> " update the system settings from my vimrc file
"----- write out html file
map ,h :source $VIM/vim70/syntax/2html.vim<cr>:w<cr>:clo<cr>
 

" Common command line typos
 "cmap W w
"cmap Q q

" Keyboard mapping for numeric keypad
imap <Esc>OM <c-m>
imap <Esc>OM <c-m>
imap <Esc>OP <nop>
map <Esc>OP <nop>
imap <Esc>OQ /
map <Esc>OQ /
imap <Esc>OR *
map <Esc>OR *
imap <Esc>OS -
map <Esc>OS -
 
imap <Esc>Ol +
imap <Esc>Om -
imap <Esc>On ,
imap <Esc>Op 0
imap <Esc>Oq 1
imap <Esc>Or 2
imap <Esc>Os 3
imap <Esc>Ot 4
imap <Esc>Ou 5
imap <Esc>Ov 6
imap <Esc>Ow 7
imap <Esc>Ox 8
imap <Esc>Oy 9
imap <Esc>Oz 0

nmap <silent> <A-Up> :wincmd k<CR>
nmap <silent> <A-Down> :wincmd j<CR>
nmap <silent> <A-Left> :wincmd h<CR>
nmap <silent> <A-Right> :wincmd l<CR>

if has("cscope")

    """"""""""""" Standard cscope/vim boilerplate

    " use both cscope and ctag for 'ctrl-]', ':ta', and 'vim -t'
    "set cscopetag

    " check cscope for definition of a symbol before checking ctags: set to 1
    " if you want the reverse search order.
    set csto=0

    "cs add cscope.out  
    " add any cscope database in current directory
    if filereadable("cscope.out")
        cs add cscope.out  
    " else add the database pointed to by environment variable 
    "elseif $CSCOPE_DB != ""
     "   cs add $CSCOPE_DB
    endif

    " show msg when any other cscope db added
    set cscopeverbose  


    """"""""""""" My cscope/vim key mappings
    "
    " The following maps all invoke one of the following cscope search types:
    "
    "   's'   symbol: find all references to the token under cursor
    "   'g'   global: find global definition(s) of the token under cursor
    "   'c'   calls:  find all calls to the function name under cursor
    "   't'   text:   find all instances of the text under cursor
    "   'e'   egrep:  egrep search for the word under cursor
    "   'f'   file:   open the filename under cursor
    "   'i'   includes: find files that include the filename under cursor
    "   'd'   called: find functions that function under cursor calls
    "
    " Below are three sets of the maps: one set that just jumps to your
    " search result, one that splits the existing vim window horizontally and
    " diplays your search result in the new window, and one that does the same
    " thing, but does a vertical split instead (vim 6 only).
    "
    " I've used CTRL-\ and CTRL-@ as the starting keys for these maps, as it's
    " unlikely that you need their default mappings (CTRL-\'s default use is
    " as part of CTRL-\ CTRL-N typemap, which basically just does the same
    " thing as hitting 'escape': CTRL-@ doesn't seem to have any default use).
    " If you don't like using 'CTRL-@' or CTRL-\, , you can change some or all
    " of these maps to use other keys.  One likely candidate is 'CTRL-_'
    " (which also maps to CTRL-/, which is easier to type).  By default it is
    " used to switch between Hebrew and English keyboard mode.
    "
    " All of the maps involving the <cfile> macro use '^<cfile>$': this is so
    " that searches over '#include <time.h>" return only references to
    " 'time.h', and not 'sys/time.h', etc. (by default cscope will return all
    " files that contain 'time.h' as part of their name).


    " To do the first type of search, hit 'CTRL-\', followed by one of the
    " cscope search types above (s,g,c,t,e,f,i,d).  The result of your cscope
    " search will be displayed in the current window.  You can use CTRL-T to
    " go back to where you were before the search.  
    "

    nmap s :cs find s <C-R>=expand("<cword>")<CR><CR>	
    nmap g :cs find g <C-R>=expand("<cword>")<CR><CR>	
    nmap c :cs find c <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-y> :cs find i <C-R>=expand("<cword>")<CR><CR>	
    nmap e :cs find e <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-f> :cs find f <C-R>=expand("<cfile>")<CR><CR>	
    nmap <C-d> :cs find d <C-R>=expand("<cfile>")<CR><CR>	

    nmap <C-@>ii :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
    "nmap d :cs find d <C-R>=expand("<cword>")<CR><CR>	


    " Using 'CTRL-spacebar' (intepreted as CTRL-@ by vim) then a search type
    " makes the vim window split horizontally, with search result displayed in
    " the new window.
    "
    " (Note: earlier versions of vim may not have the :scs command, but it
    " can be simulated roughly via:
    "    nmap <C-@>s <C-W><C-S> :cs find s <C-R>=expand("<cword>")<CR><CR>	

    nmap ss :vert scs find s <C-R>=expand("<cword>")<CR><CR>	
    nmap gs :vert scs find g <C-R>=expand("<cword>")<CR><CR>	
    nmap cs :vert scs find c <C-R>=expand("<cword>")<CR><CR>	
    nmap ts :scs find t <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-@>e :scs find e <C-R>=expand("<cword>")<CR><CR>	
    "nmap <C-f> :scs find f <C-R>=expand("<cfile>")<CR><CR>	
    nmap <C-@>i :scs find i ^<C-R>=expand("<cfile>")<CR>$<CR>	
    nmap <C-@>d :scs find d <C-R>=expand("<cword>")<CR><CR>	


    " Hitting CTRL-space *twice* before the search type does a vertical 
    " split instead of a horizontal one (vim 6 and up only)
    "
    " (Note: you may wish to put a 'set splitright' in your .vimrc
    " if you prefer the new window on the right instead of the left

    nmap sh :scs find s <C-R>=expand("<cword>")<CR><CR>
    nmap gh :scs find g <C-R>=expand("<cword>")<CR><CR>
    nmap ch :scs find c <C-R>=expand("<cword>")<CR><CR>
    nmap th :scs find t <C-R>=expand("<cword>")<CR><CR>
    nmap <C-@><C-@>e :vert scs find e <C-R>=expand("<cword>")<CR><CR>
    nmap <C-@><C-@>f :vert scs find f <C-R>=expand("<cfile>")<CR><CR>	
    nmap <C-@><C-@>i :vert scs find i ^<C-R>=expand("<cfile>")<CR>$<CR>	
    nmap <C-@><C-@>d :vert scs find d <C-R>=expand("<cword>")<CR><CR>


    """"""""""""" key map timeouts
    "
    " By default Vim will only wait 1 second for each keystroke in a mapping.
    " You may find that too short with the above typemaps.  If so, you should
    " either turn off mapping timeouts via 'notimeout'.
    "
    "set notimeout 
    "
    " Or, you can keep timeouts, by uncommenting the timeoutlen line below,
    " with your own personal favorite value (in milliseconds):
    "
    "set timeoutlen=4000
    "
    " Either way, since mapping timeout settings by default also set the
    " timeouts for multicharacter 'keys codes' (like <F1>), you should also
    " set ttimeout and ttimeoutlen: otherwise, you will experience strange
    " delays as vim waits for a keystroke after you hit ESC (it will be
    " waiting to see if the ESC is actually part of a key code like <F1>).
    "
    set ttimeout 
    "
    " personally, I find a tenth of a second to work well for key code
    " timeouts. If you experience problems and have a slow terminal or network
    " connection, set it higher.  If you don't set ttimeoutlen, the value for
    " timeoutlent (default: 1000 = 1 second, which is sluggish) is used.
    "
    set ttimeoutlen=100

endif

highlight ColorColumn ctermbg=magenta
call matchadd('ColorColumn', '\%81v', 100)

let mapleader = ","
execute pathogen#infect()
call pathogen#helptags() " generate helptags for everything in 'runtimepath'
nnoremap <leader>l :TagbarToggle <CR>
nnoremap <leader>gs :Gstatus<CR>
nnoremap <leader>gc :Gcommit -v -q<CR>
nnoremap <leader>ga :Gcommit --amend<CR>
nnoremap <leader>gt :Gcommit -v -q %<CR>
nnoremap <leader>gd :Gvdiff<CR>
nnoremap <leader>ge :Gedit<CR>
nnoremap <leader>gr :Gread<CR>
nnoremap <leader>gw :Gwrite<CR><CR>
nnoremap <leader>gl :silent! Glog<CR>
nnoremap <leader>gp :Ggrep<Space>
nnoremap <leader>gm :Gmove<Space>
nnoremap <leader>gb :Git branch<Space>
nnoremap <leader>go :Git checkout<Space>
nnoremap <leader>gps :Dispatch! git push<CR>
nnoremap <leader>gpl :Dispatch! git pull<CR>
"set statusline=%F\ %m\ %{fugitive#statusline()}\ %y%=%l,%c\ %P
set statusline=%<%f\ %h%m%r%{fugitive#statusline()}%=%-14.(%l,%c%V%)\ %P
hi StatusLine ctermbg=white ctermfg=black 
