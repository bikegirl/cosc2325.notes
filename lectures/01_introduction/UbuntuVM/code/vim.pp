class vim {

    package { 'vim':
        ensure => present,
    }

    file { '/etc/vim/vimrc':
        content => template('vim/vimrc.erb'),
    }
}
