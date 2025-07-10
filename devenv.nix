{ pkgs, ... }:

{
  packages = with pkgs; [
    qmk
    entr
    git
  ];

  scripts = {
    clean.exec = "rm -rf ./qmk";

    install.exec = ''
      qmk config user.qmk_home=$(pwd)/qmk
      qmk setup -y

      ln -s $(pwd)/planck $(pwd)/qmk/keyboards/planck/keymaps/nobe4
      ln -s $(pwd)/ferris $(pwd)/qmk/keyboards/ferris/keymaps/nobe4
    '';

    rev5.exec = "qmk flash -kb planck/rev5 -km nobe4";
    rev6.exec = "qmk flash -kb planck/rev6 -km nobe4";
    ferris.exec = "CONVERT_TO=rp2040_ce qmk flash -kb ferris/sweep -km nobe4";

    watch.exec = "git ls-files | entr -c -r $1";
  };
}
