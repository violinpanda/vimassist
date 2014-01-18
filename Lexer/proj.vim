" proj path;
let s:projpath = 'D:\Projects\Compilers\VimAssist\Lexer\'

" tags, cscope and plugin settings;
let &path.=','.s:projpath.'**'
let &tags.=','.s:projpath.'tags'
CtrlPClearAllCaches
cs kill -1
let s:csaddexpr = 'cs add '.s:projpath.'cscope.out'
exec s:csaddexpr
let s:cdpathexpr = 'cd '.s:projpath
exec s:cdpathexpr

" vim settings;
" remove '-i' to disable slow 'including file' completion;
set complete-=i
" prevent preview window;
set completeopt-=preview

