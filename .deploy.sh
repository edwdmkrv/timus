#! /bin/sh -e

# $1 - TRAVIS_BUILD_NUMBER
# $2 - BINTRAY_API_KEY

baseurl='https://api.bintray.com/content'
project='print_ip'
name='print_ip'
version="0.0.$1"
user='edwdmkrv'
params=';deb_distribution=xenial;deb_component=main;deb_architecture=amd64;publish=1'

for component in 1000 1001 1264 1293 1409 1785 1787 1877 2001 2012 do;
	package="${name}-${component}_${version}_amd64.deb"
	curl -T "$package" -u "${user}:$2" "$baseurl/$user/$project/$name/$version/pool/main/${name::1}/$name/$package$params"
done