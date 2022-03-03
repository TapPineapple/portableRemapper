#pragma once

#include <unordered_map>
#include <Windows.h>

const enum vkCodes : DWORD
{
	A = 0x41,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
};

const std::unordered_map<DWORD, DWORD> umColemak
({
	{Q, Q},
	{W, W},
	{E, F},
	{R, P},
	{T, G},
	{Y, J},
	{U, L},
	{I, U},
	{O, Y},
	{P, VK_OEM_1},
	{A, A},
	{S, R},
	{D, S},
	{F, T},
	{G, D},
	{H, H},
	{J, N},
	{K, E},
	{L, I},
	{VK_OEM_1, O},
	{Z, Z},
	{X, X},
	{C, C},
	{V, V},
	{B, B},
	{N, K},
	{M, M}
});
