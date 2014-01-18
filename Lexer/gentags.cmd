:: gentags.sql.scope.csharp.vim.py.cpp

:: ctags usage

:: - use ctags --list-languages to list all supported languages;

:: - use ctags --list-kinds=[languages|all] to list supported tag kinds;


:: create cscope.files for ctags and cscope to index;

:: in windows os, use the following "FilesScanner" to do the job;

FilesScanner -path . -include "^(.*\.cs|.*\.xaml|.*\.script|.*\.view|.*\.sql|.*\.vim|.*\.c|.*\.cpp|.*\.h|.*\.cxx|.*\.hxx|.*\.py)$" -exclude "^(.*\\\.g\.cs|.*\\Debug\\.*|.*\\obj\\.*|.*\\bin\\.*)$" > cscope.files


:: create indices;

ctags.exe --recurse --exclude="bin" --exclude="obj" -L cscope.files --extra=+fq --fields=+ialnmzS --sql-kinds=cfFLpPstTvieURDVnxy --c#-kinds=cEfgilmnps --vim-kinds=acfmv --python-kinds=cfmvi --c++-kinds=cdefgmnstuvxlp

cscope -Rbqk
