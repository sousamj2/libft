set pagination off
set debuginfod enabled on
# layout src

# b 30
# commands
# printf "nchars [%ld], negative [%d], n_long [%ld], n_copy [%ld]\n", \
#        *nchars, *negative, *n_long, n_longcopy
# end

# b 33
# commands
# printf "nchars [%ld], negative [%ld], n_long [%ld]\n", *nchars, *negative, *n_long
# printf "retval [%p] \n", retval
# end

# b 42
# commands
# record
# printf "retval [%s] \n", retval
# end
b ft_itoa_mem

b f_get_max_power

b 75
# b 75
# commands
# printf "*retval [%c] \n", *retval
# printf "retval [%s] \n", retval
# printf "n_long [%ld] neg[%ld] nchars[%ld]\n", n_long, neg, nchars 
# end

# b 77
# commands
# printf "power10[%ld] \n", power10
# end

# b 81
# commands
# record stop
# printf "power10[%ld] \n", power10
# printf "*retval[%c] at [%p]\n", *retval, retval
# printf "n_long[%ld] \n", n_long
# end

# b 83
# commands
# printf "power10[%ld] \n", power10
# printf "*retval[%c] at [%p]\n", *retval, retval
# printf "n_long[%ld] \n", n_long
# end

# b 85
# commands
# printf "power10[%ld] \n", power10
# printf "*retval[%c] at [%p]\n", *retval, retval
# printf "n_long[%ld] \n", n_long
# end

b 80
commands
printf "power10[%ld] \n", power10
printf "*retval[%c] at [%p]\n", *retval, retval
printf "n_long[%ld] \n", n_long
printf "retval[%s] \n", retval
end


b 81
commands
printf "power10[%ld] \n", power10
printf "*retval[%c] at [%p]\n", *retval, retval
printf "n_long[%ld] \n", n_long
printf "retval[%s] \n", retval
end

start
continue
