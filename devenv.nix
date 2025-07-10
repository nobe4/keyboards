{ pkgs, ... }:

{
    packages = with pkgs; [
        qmk
        entr
    ];
}
