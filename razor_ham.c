/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   razor_ham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:47:01 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/09 00:06:56 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bresenDraw (x₀, y₀, x₁, y₁)
	if x₀ == x₁ && y₀ == y₁
		draw(x₀, y₀)
		end

	Δx = x₁ - x₀
	θx = -1 if Δx < 0, else 1
	Δy = y₁ - y₀
	θy = -1 if Δy < 0, else 1

	if abs(Δy) < abs(Δx)
		θline = Δy / Δx
		pitch = y₀ - slope * x₀
		while (x₀ != x₁)
			draw(x₀, int_round(θline * x₀ + pitch))
			x₀ += θx
	else
		θline = Δx / Δy
		pitch = x₀ - slope * y₀
		while (y₀ != y₁)
			draw(int_round(θline * y₀ + pitch), y₀)
			y₀ += θy
	draw(x₁, y₁)
