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

    ferris.exec = ''
      ferris-wait-device "right"
      ferris-flash

      ferris-wait-device "left"
      ferris-flash
    '';

    ferris-wait-device.exec = ''
      read -p "Plug and reset twice the $1 side, then press enter..."

      device='Raspberry Pi RP2 Boot'
      lsusb | grep "$device" || \
          { echo "Did not find the bootable device '$device'"; exit 1; }
    '';

    ferris-flash.exec = ''
      sleep 1
      sudo dmesg | tail -n 10

      read -p "Enter the device (e.g. /dev/sda1): /dev/" device

      # Expected location of the ferris drive.
      # https://github.com/qmk/qmk_firmware/blob/87e5df1b9ef59440787d065a126b9368fae32c44/util/uf2conv.py#L210-L231
      sudo mount -m /dev/$device /media/ferris -o uid=nobe4 -o gid=users

      CONVERT_TO=rp2040_ce qmk flash -kb ferris/sweep -km nobe4

      sudo umount /media/ferris
    '';

    watch.exec = "git ls-files | entr -c -r $1";
  };
}
