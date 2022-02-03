#!/usr/bin/julia

# Autor: Krzysztof Tałałaj
println("loading JuMP")
using JuMP
println("loading GLPK solver")
using GLPK
using JSON
using LinearAlgebra

data = JSON.parsefile(ARGS[1])
model = Model(GLPK.Optimizer)

size = data["vertices"]
start = 1
finish = size

capacity = zeros(Int16, (size, size))
for edge in keys(data["edges"])
    splitted = split(edge)
    capacity[parse(Int, splitted[1]), parse(Int, splitted[end])] = data["edges"][edge]
end

# Zmienne przepływu w grafie
@variable(model, 0 <= x[i = 1:size, j = 1:size] <= capacity[i, j], Int)

# Flow w punkcie startowym i końcowym są przeciwne
@constraint(model, sum(x[start, :]) - sum(x[:, start]) == - sum(x[finish, :]) + sum(x[:, finish]))

# Flow w pozostałych punktach jest równy 0
@constraint(model, [i = 1:size; i != start && i != finish], sum(x[i, :]) == sum(x[:, i]))

# Maksymalizujemy przepływ w starcie
@objective(model, Max, sum(x[start, :]) - sum(x[:, start]))

optimize!(model)

println("\nRESULTS:")
println(solution_summary(model))
for i = 1:size, j = 1:size
    if (value(x[i, j]) > 0.0)
        println("(", i, ",", j, ") = ", value(x[i, j]), "/", capacity[i, j])
    end
end