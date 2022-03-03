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


const std::unordered_map<DWORD, DWORD>umVKtoHW
({
	{Q, 16},
	{W, 17},
	{E, 18},
	{R, 19},
	{T, 20},
	{Y, 21},
	{U, 22},
	{I, 23},
	{O, 24},
	{P, 25},
	{A, 30},
	{S, 31},
	{D, 32},
	{F, 33},
	{G, 34},
	{H, 35},
	{J, 36},
	{K, 37},
	{L, 38},
	{VK_OEM_1, 39},
	{Z, 44},
	{X, 45},
	{C, 46},
	{V, 47},
	{B, 48},
	{N, 49},
	{M, 50}
	});
