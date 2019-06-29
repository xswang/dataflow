/*
 * thread.h
 * Copyright (C) 2018 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef THREAD_H
#define THREAD_H
namespace dataflow {
template <typename ThreadType>
class ThreadPool {
 public: 
  ThreadPool(size_t thread_num);
  ~ThreadPool();
 private:
  std::vector<ThreadType> workers_;
};
}

#endif /* !THREAD_H */
