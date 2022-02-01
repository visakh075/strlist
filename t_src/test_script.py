import os
os.system("rm test_results")
for i in [0,1,2,3,5]:
    t_specfile=open("lib/test_spec.h","w+")
    test_spec="#define TEST_NX_EN 1\n"+"#define TEST_NX "+str(i)
    t_specfile.write(test_spec)
    t_specfile.close()
    
    head_str='='*30+'Test for '+str(i)+'='*30
    tail_str="="*(len(head_str))
    print(head_str)
    
    #os.system('make all')
    #
    #command_str="echo "+head_str+">>test_results"
    #print(command_str)
    os.system('echo "'+head_str+'">>test_results')
    print("\nBuild >>>>>>>>>>>>>")
    os.system('make clean_tests')
    os.system('make all_no_msg')
    print("\nOutput >>>>>>>>>>>>>")
    os.system('valgrind --leak-check=full --quiet --log-file="v-out" t_bin/strlist_test')
    os.system("cat v-out>>test_results")
    os.system('echo "'+tail_str+'">>test_results')
    os.system("rm v-out")
    print('\n'+tail_str)
    