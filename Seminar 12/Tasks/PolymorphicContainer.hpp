#pragma once

#include <vector>
#include <memory>
#include <stdexcept>
#include <concepts>

template<typename T>
concept Cloneable = requires(const T & obj) {
    { obj.clone() } -> std::same_as<std::unique_ptr<T>>;
};

template<Cloneable T>
class UniqueContainer {
    std::vector<std::unique_ptr<T>> data;

public:
    UniqueContainer() = default;

    UniqueContainer(const UniqueContainer& other) {
        data.reserve(other.data.size());
        for (const auto& ptr : other.data)
            data.push_back(ptr->clone());
    }

    UniqueContainer& operator=(const UniqueContainer& other) {
        if (this != &other) {
            UniqueContainer tmp(other);
            std::swap(data, tmp.data);
        }
        return *this;
    }

    UniqueContainer(UniqueContainer&&) noexcept = default;
    UniqueContainer& operator=(UniqueContainer&&) noexcept = default;
    ~UniqueContainer() = default;

    void add(std::unique_ptr<T> obj) {
        if (!obj) throw std::invalid_argument("Cannot add null object.");
        data.push_back(std::move(obj));
    }

    void add(const T& obj) {
        data.push_back(obj.clone());
    }

    void remove(std::size_t index) {
        if (index >= data.size())
            throw std::out_of_range("Index out of range.");
        data.erase(data.begin() + index);
    }

    T& operator[](std::size_t index) {
        if (index >= data.size())
            throw std::out_of_range("Index out of range.");
        return *data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= data.size())
            throw std::out_of_range("Index out of range.");
        return *data[index];
    }

    auto begin() { return data.begin(); }
    auto end() { return data.end(); }
    auto begin() const { return data.cbegin(); }
    auto end()   const { return data.cend(); }
};


template<Cloneable T>
class SharedDeepContainer {
    std::vector<std::shared_ptr<T>> data;

public:

    SharedDeepContainer() = default;

    SharedDeepContainer(const SharedDeepContainer& other) {
        data.reserve(other.data.size());
        for (const auto& ptr : other.data)
            data.push_back(ptr->clone());
    }

    SharedDeepContainer& operator=(const SharedDeepContainer& other) {
        if (this != &other) {
            SharedDeepContainer tmp(other);
            std::swap(data, tmp.data);
        }
        return *this;
    }

    SharedDeepContainer(SharedDeepContainer&&) noexcept = default;
    SharedDeepContainer& operator=(SharedDeepContainer&&) noexcept = default;
    ~SharedDeepContainer() = default;

    void add(std::shared_ptr<T> obj) {
        if (!obj) throw std::invalid_argument("Cannot add null object.");
        data.push_back(std::move(obj));
    }

    void add(const T& obj) {
        data.push_back(obj.clone());
    }

    void remove(std::size_t index) {
        if (index >= data.size())
            throw std::out_of_range("Index out of range.");
        data.erase(data.begin() + index);
    }

    T& operator[](std::size_t index) {
        if (index >= data.size())
            throw std::out_of_range("Index out of range.");
        return *data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= data.size())
            throw std::out_of_range("Index out of range.");
        return *data[index];
    }

    auto begin() { return data.begin(); }
    auto end() { return data.end(); }
    auto begin() const { return data.cbegin(); }
    auto end()   const { return data.cend(); }
};


template<typename T>
class SharedShallowContainer {
    std::vector<std::shared_ptr<T>> data;

public:

    void add(std::shared_ptr<T> obj) {
        if (!obj) throw std::invalid_argument("Cannot add null object.");
        data.push_back(std::move(obj));
    }

    void remove(std::size_t index) {
        if (index >= data.size())
            throw std::out_of_range("Index out of range.");
        data.erase(data.begin() + index);
    }

    T& operator[](std::size_t index) {
        if (index >= data.size())
            throw std::out_of_range("Index out of range.");
        return *data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= data.size())
            throw std::out_of_range("Index out of range.");
        return *data[index];
    }

    auto begin() { return data.begin(); }
    auto end() { return data.end(); }
    auto begin() const { return data.cbegin(); }
    auto end()   const { return data.cend(); }
};