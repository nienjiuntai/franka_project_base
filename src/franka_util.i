%module franka_util

%include <std_string.i>
%{
    // #define SWIG_FILE_WITH_INIT
    #include "franka_util.hpp"
%}

/* Let's just grab the original header file here */
%include "franka_util.hpp"