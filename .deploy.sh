#! /bin/sh -e

# $1 - TRAVIS_BUILD_NUMBER
# $2 - BINTRAY_API_KEY

baseurl='https://api.bintray.com/content'
project='timus'
name='timus'
version="0.0.$1"
user='edwdmkrv'
params=';deb_distribution=xenial;deb_component=main;deb_architecture=amd64;publish=1'

attempt='0'
attempts='9'
components='1000 1001 1073 1196 1197 1264 1293 1306 1409 1496 1545 1639 1785 1787 1820 1837 1864 1877 1880 2001 2012 2066'
failed=''

while test "$attempt" -lt "$attempts"; do
	for component in $components; do
		package="${name}-${component}_${version}_amd64.deb"

		echo
		echo 'Uploading '"$component"
 
		curl -s -X 'DELETE' -u "${user}:$2" "$baseurl/$user/$project/$name/$version/pool/main/${name::1}/$name/$package$params" > '/dev/null'
		headers="`curl -s -D '/dev/stdout' -T "$package" -u "${user}:$2" "$baseurl/$user/$project/$name/$version/pool/main/${name::1}/$name/$package$params"`"
		echo "$headers" | grep -q -E 'HTTP/.* 20. .reated'
		rc=$?

		if test $rc -ne 0; then
			failed="$failed $component"
		fi

		if test "$rc" -eq 0; then
			echo 'Uploaded successfully'
		else
			echo 'Upload failed'
			echo 'Items to try to upload again: '"$failed"
			echo 'HTTP headers:'
			echo "$headers"
		fi
	done

	attempt="`expr "$attempt" + 1`"

	if test x"$failed" != x"$components"; then
		attempt='0'
		components="$failed"

		if test -n "$failed"; then
			echo 'Some components uploaded successfully, the attempt counter is reset'
		fi
	fi

	failed=''

	if test -z "$components"; then
		break
	fi

	echo 'Trying to upload again the next items (attempt '"$attempt"'): '"$components"
done
