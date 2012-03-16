; This file was auto-generated by drush make
core = 7.x

api = 2
projects[drupal][version] = "7.12"

; RedHen module suite
projects[redhen][type] = "module"
projects[redhen][download][type] = "git"
projects[redhen][download][url] = "git://git.drupal.org/project/redhen.git"
projects[redhen][download][branch] = "master"

; RedHen dependencies
projects[relation][subdir] = "contrib"
projects[entity][subdir] = "contrib"
projects[ctools] = "1.x-dev"
projects[ctools][subdir] = "contrib"
projects[registration][subdir] = "contrib"

; Additional contrib modules and themes (Not required)
projects[admin_menu] = "contrib"
projects[features][subdir] = "contrib"
projects[rules][subdir] = "contrib"
projects[token][subdir] = "contrib"
projects[strongarm][subdir] = "contrib"
projects[views][subdir] = "contrib"
projects[adaptivetheme][type] = "theme"
projects[at-commerce][type] = "theme"
projects[at-commerce] = "2.0-rc3"

; Developer tools
projects[devel][subdir] = "developer"
projects[diff][subdir] = "developer"