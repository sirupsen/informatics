program grader;

uses fog;

{$L paddle.o}
{$L graderlib.o}
{$LINKLIB c}

function init : longint; cdecl; external;

var
    N: longint;

begin
	N := init();
	goSail(N);
end.
