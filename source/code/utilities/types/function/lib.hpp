#pragma once
#include <future>
#include <thread>
#include <functional>


template <typename TF, typename TDuration, class... TArgs>
std::result_of_t<TF&&(TArgs&&...)> run_with_timeout(TF&& f, TDuration timeout, TArgs&&... args)
{
    using R = std::result_of_t<TF&&(TArgs&&...)>;
    std::packaged_task<R(TArgs...)> task(f);
    auto future = task.get_future();
    std::thread thr(std::move(task), std::forward<TArgs>(args)...);
    if (future.wait_for(timeout) != std::future_status::timeout)
    {
       thr.join();
       return future.get(); // this will propagate exception from f() if any
    }
    else
    {
       thr.detach(); // we leave the thread still running
       throw std::runtime_error("Timeout");
    }
}

template <typename Fun, typename Duration>
bool run_lambda_with_timeout(Duration timeout, Fun fun)
{
    std::packaged_task<void()> task(fun);
    auto future = task.get_future();
    std::thread thr(std::move(task));
    if (future.wait_for(timeout) != std::future_status::timeout)
    {
       thr.join();
       future.get(); // this will propagate exception from f() if any
       return true;
    }
    else
    {
       thr.detach(); // we leave the thread still running
       return false;
    }
}