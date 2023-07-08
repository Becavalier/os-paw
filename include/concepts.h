template <typename T = int> 
concept hasSysconf = requires(T t) {
  { sysconf(t) } -> std::same_as<long>;
};
