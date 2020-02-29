# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|

  config.vm.box = "ubuntu/bionic64"

  config.vm.provider "virtualbox" do |vb|
    vb.memory = "1024"
  end

  config.vm.provision "shell", inline: <<-SHELL
    export DEBIAN_FRONTEND=noninteractive
    add-apt-repository ppa:vriviere/ppa
    apt-get update
    apt-get install --yes cross-mint-essential
    cp /vagrant/install_emutos.sh .
    chmod +x ./install_emutos.sh
    ./install_emutos.sh
  SHELL
end
