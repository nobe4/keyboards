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
      ${pkgs.qmk}/bin/qmk config user.qmk_home=$(pwd)/qmk
      ${pkgs.qmk}/bin/qmk setup -y

      ln -s $(pwd)/planck $(pwd)/qmk/keyboards/planck/keymaps/nobe4
      ln -s $(pwd)/ferris $(pwd)/qmk/keyboards/ferris/keymaps/nobe4
    '';

    rev5.exec = ''
      ${pkgs.git}/bin/git ls-files | \
          entr -c -r ${pkgs.qmk}/bin/qmk flash -kb planck/rev5 -km nobe4
    '';

    rev6.exec = ''
      ${pkgs.git}/bin/git ls-files | \
          entr -c -r ${pkgs.qmk}/bin/qmk flash -kb planck/rev6 -km nobe4
    '';

    ferris.exec = ''
      ${pkgs.git}/bin/git ls-files | \
          entr -c -r CONVERT_TO=rp2040_ce ${pkgs.qmk}/bin/qmk flash -kb ferris/sweep -km nobe4
    '';
  };
}
