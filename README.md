## mygcc

**功能**
- 具备 gcc build 功能
- 具备 gcc link 功能
- 打印主机名
- 把输入的 txt 文件，加行`hello world`，输出


**编译**
```shell
cd mygcc
./build.sh
```


## example

使用 mygcc 编译的例子


## 扩展

可以接 icecream fastbuild 等分布式编译，因为 mygcc 已经伪装成 gcc 了

## icecream

icecream 具有创建虚拟环境功能，会自动分发给从机，这样即使从机不装 mygcc 可以没问题。（当然从机还是要安装 icesream ，这个无解）
