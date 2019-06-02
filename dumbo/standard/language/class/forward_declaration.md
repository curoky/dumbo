# forward declaration

## with unique_ptr/shared_ptr

`unique_ptr` 的模板在构造时可以是未完成类型，但在调用删除器（析构时）必须是完成类型。
`shared_ptr` 的模板在构造时必须是完成类型，但在调用删除器（析构时）可以是未完成类型。

即如果使用 Plmpl 模式 with `unique_ptr`，必须要把析构放在 cpp 中并且不能 `inline`

## refference

- [https://en.cppreference.com/w/cpp/memory/unique_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr)
- [https://stackoverflow.com/questions/27336779/unique-ptr-and-forward-declaration](https://stackoverflow.com/questions/27336779/unique-ptr-and-forward-declaration)
- [https://stackoverflow.com/questions/13414652/forward-declaration-with-unique-ptr](https://stackoverflow.com/questions/13414652/forward-declaration-with-unique-ptr)
