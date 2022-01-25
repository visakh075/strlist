Text='''Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc eget tellus velit. Aliquam in nibh laoreet velit sollicitudin tristique at ut arcu. Nulla facilisi. Donec sem nunc, malesuada a tincidunt sit amet, viverra a nunc. Fusce mollis purus id blandit laoreet. Mauris quis enim ultrices, placerat elit sit amet, vestibulum eros. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Aenean ut iaculis odio, sed sodales dui.
Nullam id enim quis felis aliquam pharetra. Aliquam ut pulvinar libero. Cras feugiat urna eget pretium convallis. Pellentesque suscipit, velit a fringilla efficitur, justo mauris luctus erat, et elementum arcu leo vel erat. Donec nec porta ipsum. Vestibulum faucibus augue sit amet elit blandit porta. Integer et mollis lacus, in sodales libero. Duis orci diam, porta vel venenatis a, viverra a tellus. Proin hendrerit ipsum at rhoncus lobortis. Donec rutrum velit a molestie dapibus. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Nunc vulputate quam at est consequat eleifend eget at urna. Curabitur maximus feugiat condimentum.
Mauris sed urna ligula. Phasellus venenatis tempus varius. Vivamus at tempor erat. Phasellus dictum lobortis libero. Pellentesque tincidunt elit a risus imperdiet tempor. Vivamus neque mi, semper vitae enim semper, blandit sagittis tortor. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Curabitur ante magna, imperdiet sed facilisis non, rutrum vel nunc. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Ut nec nisl at nibh rhoncus congue. Sed sagittis sodales lobortis. Aenean eu rhoncus velit. Praesent sed eros a lorem blandit lacinia. Sed varius at dolor et tempus.
Aenean luctus magna quis nisi vehicula, vitae aliquam massa viverra. Aliquam at imperdiet ipsum, ac efficitur metus. Etiam mattis nibh vitae erat suscipit varius. Mauris porta viverra tincidunt. Nullam a odio dui. Ut volutpat imperdiet est eu vulputate. Fusce et ante ut elit laoreet maximus. Curabitur eget justo sodales, volutpat purus vitae, mollis urna. Nunc laoreet lacus felis, vel accumsan quam feugiat eu. Sed nibh dui, maximus eu suscipit in, rutrum nec lectus. Integer mollis interdum tincidunt. Phasellus libero justo, hendrerit quis venenatis elementum, ullamcorper efficitur lorem. Suspendisse accumsan tincidunt ipsum, eget vestibulum sem dapibus eget. Nam sit amet felis et ligula cursus fermentum non eget justo. Donec molestie pretium maximus.
Proin elementum est a lacus euismod tincidunt. Morbi ut ipsum id ex accumsan mattis. Proin a tempor ligula. Cras vehicula libero eu facilisis lacinia. Maecenas porttitor rutrum dui ut fermentum. Aliquam eget feugiat sapien. Pellentesque malesuada malesuada pharetra. Morbi rutrum sagittis nibh eu sodales. Cras faucibus erat nec interdum ornare. Donec eu ex tellus. Cras efficitur consequat cursus. Pellentesque nec felis vel massa ultricies placerat.'''
words=Text.split()

extra ='''



'''

f=open("dummy.h","w")
dmw=0
f.write('const char* dummy['+str(len(words))+']={\n')
for word in words:
    f.write('"'+word+'"')
    dmw+=1
    if(dmw!=len(words)):
        f.write(',\n')
f.write('};')
f.close()
