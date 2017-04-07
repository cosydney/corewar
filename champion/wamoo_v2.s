.name "Wamoo"
.comment "Awaken, my masters!"

prot:	st r1,:var1
		st r10,-4
		ld :var1, r1
		ld %191103999,r10
		st r10,:var2
		st r1, 6
		live %1
		fork %:begin
		live %1
		live %1
		live %1
		live %1
		live %1
		live %1
		live %1
		live %1
		live %1
		live %1
		live %1
		live %1
begin:	live %1
		fork %:part2
part1:	fork %:part4
		ld 110,r3
		ld %0,r4
		and r11,%0,r11
		zjmp %:go
part2:	fork %:part3
		ld 88,r3
		ld %4,r4
		and r11,%0,r11
		zjmp %:go
part3:	ld %1677918270,r3 #0x640300a6
		ld %8,r4
		and r11,%0,r11
		zjmp %:go
part4:	ld %67698746,r3 #0x040900a2
		ld %12,r4
		and r11,%0,r11
		zjmp %:go
go:		sti r3,%67,r4
		zjmp %61
		live %1
var1:	st r11,r11
var2:	st r11,r11
