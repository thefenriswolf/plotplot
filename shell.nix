
{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  buildInputs = [
    pkgs.clang_13
    pkgs.clang-tools
    pkgs.clang-analyzer
    pkgs.lldb
    pkgs.lld_13
    pkgs.ncurses
    pkgs.man
    pkgs.man-pages
    pkgs.bashInteractive
  ];
}

